# ECE484_IndividualFinal

This project aims to create a game display system utilizing Arduino boards and various sensors to determine game states and point values. The communication between different Arduino nodes is facilitated using nRF24L01 wireless modules. The display incorporates an LCD_I2C screen to showcase point values and signal game status.

Components Used
Arduino boards (node00, node01, node02)
nRF24L01 wireless modules
LCD_I2C display
Various sensors 
Functionality
The main functionalities of the project include:

Communication Protocol: Utilizing nRF24L01 modules, the system establishes communication between three Arduino nodes (node00, node01, node02).

Sensor Integration: The system incorporates various sensors to determine point values and game states. These sensors feed data to the Arduino nodes for processing.

Game State Determination: Through sensor inputs, the Arduino nodes collectively determine the game state, including whether the game is ongoing or has ended.

LCD Display: The Arduino node00 acts as the receiver and is connected to an LCD_I2C display. This display showcases point values and signals when the game is over or ongoing.

Audio Feedback: Optionally, the system can provide audio feedback, such as playing a sound when the game concludes, providing an audible signal of game completion.

Communication Protocol
The communication between Arduino nodes is achieved using the nRF24L01 wireless modules. These modules facilitate reliable and efficient data transfer between the nodes, enabling seamless coordination and synchronization of game states and point values.

Usage
To utilize the system:

Connect the Arduino boards (node00, node01, node02) and nRF24L01 modules as per the wiring diagram provided with the code.

Upload the respective Arduino sketches to each node, ensuring proper configuration and initialization of the nRF24L01 modules.

Power on the system and monitor the LCD_I2C display connected to node00 for game status and point values.

Interact with the sensors or input devices configured in the system to affect game states and point values.

Future Improvements
Future enhancements to the project could include:

Expansion of sensor integration for more diverse gameplay experiences.
Implementation of additional communication protocols for redundancy or improved data transmission.
Enhancement of user interface elements, such as graphical feedback on the LCD display.
Integration of a wider range of audio feedback options for enhanced user engagement.
Contributors
Your Name/Organization - Project Lead
License
This project is licensed under the MIT License, granting open-source usage, modification, and distribution under the specified terms.


