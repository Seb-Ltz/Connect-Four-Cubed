#include <iostream>
#include "BordTest.hpp"
#include "../Board.h"

void BordTest::init()
{
    Board board;

    board.dropSphere(0, 0, Board::PlayerColor::PlayerRed);
    board.dropSphere(1, 0, Board::PlayerColor::PlayerGreen);
    board.dropSphere(2, 0, Board::PlayerColor::PlayerRed);
    board.dropSphere(3, 0, Board::PlayerColor::PlayerGreen);

    //Board[0] after last instructions
    //R000
    //G000
    //R000
    //G000



    board.dropSphere(0, 1, Board::PlayerColor::PlayerRed);
    board.dropSphere(0, 0, Board::PlayerColor::PlayerGreen);
    board.dropSphere(0, 2, Board::PlayerColor::PlayerRed);
    board.dropSphere(0, 0, Board::PlayerColor::PlayerGreen);

    //Board[0] after last instructions
    //RRR0
    //G000
    //R000
    //G000
    //at [1] and [2] at 0,0 there are 2 Green balls

    board.dropSphere(0, 2, Board::PlayerColor::PlayerRed);
    //Player red should have won

    Board::GameState gameState = board.getGameState();




    if(board.getSphere(0, 0, 0) == Board::Sphere::RedSphere
    && board.getSphere(0, 0, 1) == Board::Sphere::GreenSphere
    && board.getSphere(0, 0, 2) == Board::Sphere::GreenSphere
    && board.getSphere(0, 1, 0) == Board::Sphere::RedSphere
    && board.getSphere(1, 0, 0) == Board::Sphere::GreenSphere
    && board.getSphere(1, 1, 1) == Board::Sphere::NoSphere)
    {
        std::cout << "All spheres well placed !! No errors !" << '\n';
    }
    else
    {
        std::cerr << "Some spheres aren't at their correct position !" << '\n';
        if(board.getSphere(0, 0, 0) != Board::Sphere::RedSphere)
        {
            std::cerr << "Sphere at 0 0 0 is not Red : " << board.getSphere(0, 0, 0) << '\n';
        }
        if(board.getSphere(0, 0, 1) != Board::Sphere::GreenSphere)
        {
            std::cerr << "Sphere at 0 0 1 is not Green : " << board.getSphere(0, 0, 1) << '\n';
        }
        if(board.getSphere(0, 0, 2) != Board::Sphere::GreenSphere)
        {
            std::cerr << "Sphere at 0 0 2 is not Green : " << board.getSphere(0, 0, 2) << '\n';
        }
        if(board.getSphere(0, 1, 0) != Board::Sphere::RedSphere)
        {
            std::cerr << "Sphere at 0 1 0 is not Green : " << board.getSphere(0, 1, 0) << '\n';
        }
        if(board.getSphere(1, 0, 0) != Board::Sphere::GreenSphere)
        {
            std::cerr << "Sphere at 1 0 0 is not Green : " << board.getSphere(1, 0, 0) << '\n';
        }
        if(board.getSphere(1, 1, 1) != Board::Sphere::NoSphere)
        {
            std::cerr << "Sphere at 1 0 0 is not not a sphere : " << board.getSphere(1, 1, 1) << '\n';
        }

    }

    std::cout << "-------------------" << '\n';

    if(gameState == Board::GameState::GameWonByRed)
    {
        std::cout << "Red have won !! No errors !" << '\n';
    }
    else if(gameState == Board::GameState::Playing)
    {
        std::cerr << "Game is still playing. Red should have won !" << '\n';
    }
    else if(gameState == Board::GameState::GameWonByGreen)
    {
        std::cerr << "Game has been won by the wrong person. Red should have won !" << '\n';
    }
    else
    {
        std::cerr << "Othere state than red should have won : error!" << '\n';
    }




}

void BordTest::debugTest()
{
    Board board;

    board.dropSphere(0, 0, Board::PlayerColor::PlayerRed);
    board.dropSphere(0, 0, Board::PlayerColor::PlayerGreen);
//    board.dropSphere(0, 0, Board::PlayerColor::PlayerRed);
//    board.dropSphere(1, 0, Board::PlayerColor::PlayerRed);

    if (board.getSphere(0, 0, 1) == Board::Sphere::RedSphere) {
        std::cout << "Red sphere found" << std::endl;
    }
    if (board.getSphere(0, 0, 1) == Board::Sphere::GreenSphere) {
        std::cout << "Green sphere found" << std::endl;
    }
    else {
        std::cerr << "No red sphere found" << std::endl;
    }
}
