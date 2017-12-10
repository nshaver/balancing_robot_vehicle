# balancing_robot_vehicle
Balancing Robot Vehicle

I used this guy's YABR (Yet Another Balancing Robot) project as my guide: www.brokking.net/yabr_main.html

I used his code with some slight modifications:
- uses NRF24L01 radios instead of bluetooth to Nunchuk
- uses the pin mappings of my CNC shield whereas he directly wired to his DRV8825 drivers
- added incr/decr buttons for P and I and D to help to tune the PID variables.
