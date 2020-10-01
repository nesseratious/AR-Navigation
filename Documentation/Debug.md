## DEBUG MODE

To toggle debug mode tap on the "Debug" button located in the top left corner. The debug mode will display all vertices and their axes. This will allow you to test how the virtual world matches the real one. 
 
<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579277884.gif" />
</p>

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/Screen%20Shot%202020-04-20%20at%2010.13.37%20PM.png" />
</p>

## NAVIGATION

The navigation in this system is **not turn-based**, this means that the whole navigation path will be displayed once the user selects a destination. 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278346.gif" />
</p>


If you want to opt-out of this behavior and hide all navigation arrows that are behind the walls, you can do so by adding built-in unreals function LineTraceByChannel to the Arrow class blueprint, where the start point will be player's camera and the endpoint will be world location of the Arrow instance. Depending on whether the arrow instance was hit or not, you can call SetVisibility function to hide or unhide the arrow. The visualization of such algorithm would look like this:

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/111.png" />
</p>


And yet I do not recommend using this approach as my personal user surveys have shown that such behavior may be confusing.
