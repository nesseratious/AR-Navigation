## Configuration

#### The supplementary class that stores lists of the possible user's initial positions.

Usage: Place it anywhere on the map. Use only one instance.

Public properties: 

- InitialPositionPage: Struct - Contains a struct "Initial Positions" that stores a list of user's possible initial positions. Each InitialPosition stores a "Text"(Localizable friendly name that will be displayed in the list) and "TeleportToVertexTag" (Vertex ID which coordinates will be used to virtually teleport the user to that Vertex). The default values are missing and are implemented directly in the demo level.

- MainUIText: Struct - Contains a struct "QuickButtons" that stores a list of user's possible destinations which can be selected by the user from the main UI. Each QuickButton contains Text"(Localizable friendly name that will be displayed in the list), "Floor" Localizable friendly name of the floor that will be displayed in the main UI under the destination) and "DestinationTag" (destination Vertex ID).
