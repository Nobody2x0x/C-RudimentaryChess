#pragma once
#ifndef GAMESTATUS_H
#define GAMESTATUS_H

typedef enum GameStatus
{
    ACTIVE,
    BLACK_WIN,
    WHITE_WIN,
    FORFEIT,
    STALEMATE,
    RESIGNATION,
    NOTSTARTED
} GameStatus;

#endif