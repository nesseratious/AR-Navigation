# AR-Navigation-Documentation

The AR Navigation 
 
- 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278581.gif" />
</p>



# DEBUG MODE

Before 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579277884.gif" />
</p>

# NAVIGATION

The navigation in this system is **not turn-based**, this means that the whole navigation path will be displayed once the user selects a destination. 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278346.gif" />
</p>


If you want to opt out of this behaviour and hide all navigation arrows that are behind the walls, you can do so by adding built-in unreal's function LineTraceByChannel to the Arrow class blueprint, where the start point will be player's camera and the end point will be world location of the Arrow instance. Depending on whether the arrow instance was hit or not, you can call SetVisibility function to hide or unhide the arrow. Do not call LineTraceByChannel every frame as this will degrade performance. Put it on timer to call only 5 times per second, you can do so by wiring a CustomEvent to your functions and adding a built-in function SetTimerByFunctionName with your CustomEvent name. The visualization of such algorithm would look like this:

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/111.png" />
</p>


And yet I do not recommend using this approach as my personal user surveys have shown that such behaviour may be confusing.
