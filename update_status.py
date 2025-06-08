import pandas as pd
import re
from datetime import datetime

# CSV 불러오기
df = pd.read_csv('./solved.csv')

# 비어있는 date만 오늘 날짜로 채움
today = datetime.today().strftime('%Y-%m-%d')
if 'date' not in df.columns:
    df['date'] = today
else:
    df['date'] = df['date'].fillna(today)

# 시간 처리: '30' → '00:30:00'
df['time'] = pd.to_timedelta(df['time'].fillna(0).astype(str) + ' min')
df['time'] = df['time'].apply(lambda x: str(x).split(' ')[-1])

# 상태 정렬 우선순위
status_priority = {'solved': 0, 'solved with hint': 1, 'unsolved': 2}
df['status_order'] = df['status'].map(status_priority)

# 난이도 정렬 우선순위 (어려운 → 쉬운)
level_rank = {
    'Ruby 1': 1, 'Ruby 2': 2, 'Ruby 3': 3, 'Ruby 4': 4, 'Ruby 5': 5,
    'Diamond 1': 6, 'Diamond 2': 7, 'Diamond 3': 8, 'Diamond 4': 9, 'Diamond 5': 10,
    'Platinum 1': 11, 'Platinum 2': 12, 'Platinum 3': 13, 'Platinum 4': 14, 'Platinum 5': 15,
    'Gold 1': 16, 'Gold 2': 17, 'Gold 3': 18, 'Gold 4': 19, 'Gold 5': 20,
    'Silver 1': 21, 'Silver 2': 22, 'Silver 3': 23, 'Silver 4': 24, 'Silver 5': 25,
    'Bronze 1': 26, 'Bronze 2': 27, 'Bronze 3': 28, 'Bronze 4': 29, 'Bronze 5': 30,
    'Lv 5': 31, 'Lv 4': 32, 'Lv 3': 33, 'Lv 2': 34, 'Lv 1': 35,
}
df['level_order'] = df['level'].map(level_rank).fillna(999)

# 문제 정보 파싱
def parse_prob_name(name):
    match = re.match(r'([^ ]+) (\d+) : (.+?) \((https?://[^\)]+)\)', name)
    if match:
        return match.group(1), match.group(2), match.group(3), match.group(4)
    return '', '', name, ''

parsed = df['prob_name'].apply(parse_prob_name)
df['site'] = parsed.apply(lambda x: x[0])
df['problem_number'] = parsed.apply(lambda x: x[1])
df['problem_title'] = parsed.apply(lambda x: x[2])
df['problem_url'] = parsed.apply(lambda x: x[3])

# 정렬
df_sorted = df.sort_values(
    by=['date', 'site', 'status_order', 'level_order'],
    ascending=[False, True, True, True]
)

# Markdown 출력
markdown_output = ""

for site in df_sorted['site'].unique():
    markdown_output += "\n---\n"
    markdown_output += f"\n## {site}\n"
    site_df = df_sorted[df_sorted['site'] == site]

    for status in site_df['status'].unique():
        markdown_output += "\n---\n"
        markdown_output += f"\n**{status.upper()}**\n"
        status_df = site_df[site_df['status'] == status]

        for level in status_df['level'].unique():
            level_df = status_df[status_df['level'] == level]
            if not level_df.empty:
                markdown_output += f"\n#### {level}\n"
                markdown_output += "| Date | 풀이 시간 | Problem | Python Code | C++ Code |\n"
                markdown_output += "|------|------|---------|-------------|-----------|\n"
                for _, row in level_df.iterrows():
                    date = row['date']
                    time = row['time']
                    prob_num = row['problem_number']
                    prob_title = row['problem_title']
                    prob_url = row['problem_url']
                    code_root = row['code_root']

                    if site.lower() == '백준' and prob_num:
                        code_py = f"[python](./baekjoon/{code_root}/{prob_num}/{prob_num}.py)"
                        code_cpp = f"[c++](./baekjoon/{code_root}/{prob_num}/{prob_num}.cpp)"
                    else:
                        code_py = ""
                        code_cpp = ""

                    prob_link = f"[{prob_num} : {prob_title}]({prob_url})" if prob_url else f"{prob_num} : {prob_title}"
                    markdown_output += f"| {date} | {time} | {prob_link} | {code_py} | {code_cpp} |\n"

# 마크다운 파일 저장
with open("./solved.md", "w", encoding="utf-8") as f:
    f.write(markdown_output)

# 업데이트된 CSV 저장 (보조 열은 제거)
df[['prob_name', 'status', 'level', 'time', 'code_root', 'date']].to_csv('./solved.csv', index=False)