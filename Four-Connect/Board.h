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
        Gets a pointer to a whole column, return nullptr if out of bounds
        @param The x and z coordinates of the column
        @return A const pointer to a whole column
        */
        Sphere* const getColumn(int x, int z) const;
        /**
        Gets one sphere, return "NoSphere" if out of bounds
        @param The x, z, then y (height) of the sphere to get
        @return One sphere
        */
        Sphere getSphere(int x, int z, int y) const;

        /**
        Clears the whole board and its state
        */
        void reset();

        /**
        Returns the player who has to play now (undefined if the game state is not "Playing")
        @return Which player has to play now
        */
        inline PlayerColor getPlayerTurn() const { return m_playerTurn; }
        /**
        Returns the current game state
        @return The current state
        */
        inline GameState getGameState() const { return m_gameState; };
        /**
        Returns true if the place is inbounds AND theres space to drop a sphere
        @param The x and z coordinates
        @return True if a sphere can be dropped there
        */
        bool isThereSpace(int x, int z) const;
        /**
        Tries to drop a sphere on the provided coordinates of the board, will fail if the game state is not "Playing"
        @param The x and z coordinates of where to drop the sphere and its color
        @return A drop result, "Dropped" if it is possible
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
        Checks if theres a connect-4 in any direction on the coordinates
        @param The coordinates to check
        @return Yes or No
        */
        bool checkConnection(int x, int z, int y) const;
};


