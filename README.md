# AR-Navigation-Documentation

The AR Navigation 
 
- 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278581.gif" />
</p>



# DEBUG MODE

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579277884.gif" />
</p>

# NAVIGATION

The navigation in this system is **not turn-based**, this means that the whole navigation path will be displayed once the user selects a destination. 

<p align="center">
  <img src="https://github.com/nesseratious/AR-Navigation-Documentation/blob/master/Images/RPReplay_Final1579278346.gif" />
</p>


If you want to opt out of this behaviour and hide all navigation arrows that are behind the walls, you can do so by adding built-in unreal's function LineTraceByChannel to the Arrow class blueprint, where the start point will be player's camera and the end point will be world location of the Arrow instance. Depending on whether the arrow instance was hit or not, you can call SetVisibility function to hide or unhide the arrow. The visualization of such al
