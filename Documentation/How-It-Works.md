### How it works?

1. When the user launches your app, they will be prompted to scan the QR code used to download the app. This is needed to immediately set their position in the virtual world. Using such QR code is the most convenient way to ensure the accuracy of the user position. Also, you can use any image which can fit on an A4 sheet instead of a QR code.  

2. Alternatively, the user can select their position from a predefined list. In the demo level, this list contains 5 most popular positions for the chosen target area. Buttons are embedded into a scroll box, so you can add as many predefined positions as you want. Also, the user can select their position using manual input. In this scenario, the user's position will be set to a vertex with an ID that they have entered. To make this process easy and convenient for the user, set vertices ID to some friendly name (for example "Canteen" or "Assembly Hall").

3. After the initial position is set, the app starts the AR session. Now the app and its minimap will react to user's movements seamlessly using visual-inertial odometry provided by ARKit and ARCore runtimes.

4. The user can choose a destination point from a predefined menu or enter it manually. The app searches for a vertex with the given ID and marks it as a destination point.

5. The navigation path from the user's current location to the destination point will be calculated in real-time and displayed as a spline with animated arrows. Also, the app will display remained distance in real-time.

6. During the whole period of navigation, the app will show user's location and rotation relative to true north on the dynamic 3D minimap. 

7. The user can tap on any detected surface to place a custom marker. The marker will snap to the surface, and will show its given name and distance to the user.
