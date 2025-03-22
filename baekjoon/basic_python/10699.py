from datetime import datetime, timedelta

utc_now = datetime.utcnow()
# print(utc_now)
# print(timedelta(hours=9))
kst_now = utc_now + timedelta(hours=9)
# print(kst_now)

print(kst_now.strftime('%Y-%m-%d'))