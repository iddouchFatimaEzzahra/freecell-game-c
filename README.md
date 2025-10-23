# 🎮 Freecell Game - Implementation in C

## 📋 Project Overview
A complete implementation of the classic Freecell card game in C language, featuring console-based gameplay with full card movement logic and win condition detection.

## 🎯 Game Features
- **Complete Freecell Rules**: Implements all standard Freecell movement rules
- **Three Game Zones**:
  - Zone 1: 8 columns of cascading cards
  - Zone 2: 4 free cells for temporary storage
  - Zone 3: 4 foundation piles for completing suits
- **Card Movement**: All valid moves between zones supported
- **Win Condition**: Automatic victory detection
- **Console Interface**: Colorful text-based display

## 🏗️ Project Structure

### Data Structures
```c
typedef struct {
    int value;      // 1-13 (Ace-King)
    char type;      // 'H'=Hearts, 'C'=Clubs, 'P'=Spades, 'T'=Diamonds
} Card;

typedef struct element {
    Card card;
    struct element *next;
} element, *Pile;

