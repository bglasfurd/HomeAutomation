# Schedule Library imported
import schedule
import time
import redis

steps = ["pumpon"]

# Schedule
def sprayPlants():
	print("time to spray plants")
	i = 0
	while i < len(steps):
		queried_value = r.get('ESP') # Check ESP msgs, if empty continue with steps
		if queried_value.decode('utf-8') == "Ready for Tasks/Steps":		
			r.set('ESP', steps[i])
			i++
		else
			pass

# Task scheduling
# Every day at 08:00, 12:00, 16:00, 20:00 sprayPlants() is called.
schedule.every().day.at("08:00").do(sprayPlants)
schedule.every().day.at("12:00").do(sprayPlants)
schedule.every().day.at("16:00").do(sprayPlants)
schedule.every().day.at("20:00").do(sprayPlants)
schedule.every(1).minutes.do(sprayPlants)

#Redis
try:
    # Generate the connection
    r = redis.Redis(host='localhost', port=6379)
except Exception as e:
    print(f'Unable to connect or execute commands on Redis server: {e}')

while True:
# Loop so that the scheduling task keeps on running all time.
# Checks whether a scheduled task is pending to run or not
    schedule.run_pending()
    time.sleep(1)
