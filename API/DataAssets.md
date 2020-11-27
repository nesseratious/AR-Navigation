### QR Codes:

#### InitialPositionQRCode
 
Contains ARCandidateImage(reference image) data, such as: texture, friendly name, width, height and orientation. 


### AR Sessions:

#### ARSessionInitial
 
Contains AR session configuration used for initial positioning. World aligment is Gravity and Heading, plane detection is disabled, one reference image (QR code) is set, everyting else is at its default values.

#### ARSessionMain
 
Contains AR session configuration used for runtime positioning. World aligment is Gravity and Heading, plane detection is enabled for horizontal and vertical planes, no reference images are set, everyting else is at its default values.
