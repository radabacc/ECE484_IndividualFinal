# ECE484_IndividualFinal

This project aims to create a game display system utilizing Arduino boards and various sensors to determine game states and point values. The communication between different Arduino nodes is facilitated using nRF24L01 wireless modules. The display incorporates an LCD_I2C screen to showcase point values and signal game status.

Components Used:

-Arduino boards (node00, node01, node02)

-nRF24L01 wireless modules

-LCD_I2C display

-Various sensors 

Functionality:

The main functionalities of the project include:

Communication: Utilizing nRF24L01 modules, the system establishes communication between three Arduino nodes (node00, node01, node02).

Sensor Integration: The system incorporates various sensors to determine point values and game states. These sensors feed data to the Arduino nodes for processing.

Game State Determination: Through sensor inputs, the Arduino nodes collectively determine the game state, including whether the game is ongoing or has ended.

LCD Display: The Arduino node00 acts as the receiver and is connected to an LCD_I2C display. This display showcases point values and signals when the game is over or ongoing.

Communication Protocol
The communication between Arduino nodes is achieved using the nRF24L01 wireless modules. These modules facilitate reliable and efficient data transfer between the nodes, enabling seamless coordination and synchronization of point values. 
