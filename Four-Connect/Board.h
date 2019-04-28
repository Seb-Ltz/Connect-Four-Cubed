#pragma once

//This class defines a game, the spheres placements, its state, etc...

class Board
{
public:
    //Enums
    enum Sphere : char      //Sphere colors or no sphere
    {
        NoSphere = 0,
        RedSphere,
        GreenSphere
    };

    enum PlayerColor : char  //Same as sphere colors
    {
        PlayerRed   = Sphere::RedSphere,
        PlayerGreen = Sphere::GreenSphere
    };

    enum DropResult : char   //Describes what happened after a sphere was dropped
    {
        Dropped,
        OutOfBounds,
        NotEnoughSpace,
        NotYourTurn,
        WrongGameState,
        DroppedAndVictory
    };

    enum GameState : char    //Describes in which state the game is
    {
        StateError,
        GameWonByRed    = PlayerColor::PlayerRed,
        GameWonByGreen  = PlayerColor::PlayerGreen,
        Playing,
        GridFull
    };


    static const int DIM_X, DIM_Z, DIM_Y;
    static const int TO_CONNECT;

    /**
     * Gets a pointer to a whole column, return nullptr if out of bounds
     * @param x The x coordinate of the column
     * @param z The z coordinate of the column
     * @return A const pointer to a whole column
     */
    Sphere* const getColumn(int x, int z) const;

    /**
     * Gets one sphere, return "NoSphere" if out of bounds
     * @param x x position of the sphere to get
     * @param z z position of the sphere to get
     * @param y y position (height) of the sphere to get
     * @return One sphere at the given position
     */
    Sphere getSphere(int x, int z, int y) const;

    /**
     * Clears the whole board and its state
     */
    void reset();

    /**
     * @return the player who has to play now (undefined if the game state is not "Playing")
     */
    inline PlayerColor getPlayerTurn() const { return m_playerTurn; }

    /**
     * @return The current state
     */
    inline GameState getGameState() const { return m_gameState; };

    /**
     * Returns true if the place is inbounds AND there's space to drop a sphere
     * @param x The x position coordinate
     * @param z The z position coordinate
     * @return True if a sphere can be dropped there
     */
    bool isThereSpace(int x, int z) const;

    /**
     * Tries to drop a sphere on the provided coordinates of the board, will fail if the game state is not "Playing"
     * @param x The x coordinate of where to drop the sphere
     * @param y The y coordinate of where to drop the sphere
     * @param color The color of the sphere
     * @return A drop result, "Dropped" if it is possible
     */
    DropResult dropSphere(int x, int z, PlayerColor color);

    //Generates an empty board
    Board();
    ~Board();

private:
    Sphere* m_spheres;
    int m_sphereCount;
    const int m_maxSpheres;

    PlayerColor m_playerTurn;
    GameState m_gameState;

    /**
     * Checks if theres a connect-4 in any direction on the coordinates
     * @param x The x coordinate to check
     * @param z The z coordinate to check
     * @param y The y coordinate to check
     * @return True if there's a connect-4 in any direction
     */
    bool checkConnection(int x, int z, int y) const;

    /**
     * Sets the sphere at a certain position in the array
     * @param x The x coordinate where to place the ball
     * @param z The z coordinate where to place the ball
     * @param y The y coordinate where to place the ball
     */
    void setSphereAt(int x, int z, int y, Sphere sphere);
};