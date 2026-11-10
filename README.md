# STM32WB55 (P Nucleo WB55 board) - BLE Write Characteristic Usage Example

Configured the P Nucleo WB55 board for BLE with one service that has one write characteristic. The code was structured such that the BLE layer notifies the application layer when data is received. 

Wrote a custom BLE app for iOS (Swift/SwiftUI) which connects to any board with the matching peripheral name and using the UUIDs that match the BLE service & characteristic's UUIDs. The app displays the BLE connection status and presents the user with four buttons. Each button writes a command code to the BLE write characteristic. The board firmware passes the received command code to a command manager which executes functions based on a VTable (given the command code)...the first three commands turn on each of the nucleo board's three LEDs and the last command turns all LEDs off. Output pins on the board were connected to a logic analyzer to debug/test the behaviour (although the LEDs turning on was a good hint!). Clearly, the signals could be used to turn on any actuator (TODO: use IRLZ44Ns to turn on a solenoid & dc motor). 

The logic analyzer results shown below reflect all LEDs off and then pressing the four buttons sequentially. The green signal going low indicates the fourth command (turning all LEDs off). Chanel 0 and then 1 are then turned on my tapping the appropriate buttons on the app (at 5 seconds and just under 6 seconds). 

<img width="1205" height="431" alt="Screenshot 2026-11-10 at 4 10 17 PM" src="https://github.com/user-attachments/assets/c73cda30-f11c-47a8-a056-953c79661789" />

