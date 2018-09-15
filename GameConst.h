#pragma once
const int BOARD_ROW=3;
const int BOARD_COL=3;
const int BOARD_CELLS=BOARD_ROW*BOARD_COL;
const int SEARCH_DEPTH=6;
const int PLAYER_NULL= 0;
const int PLAYER_A= 1;
const int PLAYER_B=2;
const int LINE_DIRECTION=8;
const int LINE_CELLS=3;
const int line_idx_tbl[LINE_DIRECTION][LINE_CELLS]={
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6}
};
const char CELL_O='o';
const char CELL_X='x';
const char CELL_EMPTY='_';
const int DOUBLE_WEIGHT=10;

inline int getPeerPlayer(int player_id){return (player_id==PLAYER_A)?PLAYER_B:PLAYER_A;}
