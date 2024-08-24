/**
 * @file colors.h
 * @author Tales Oliveira (g.dev/TalesOliveira)
 * @brief  Color for your terminal
 */

#ifndef COLORS_H
#define COLORS_H

// Resetar para as configurações padrão
#define RESET "\x1B[0m"

// Faz um som (beep) no terminal
#define BELL "\x07"

// Cores de texto
#define BLACK "\x1B"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

// Cores de fundo
#define BLACK_BG "\x1B[40m"
#define RED_BG "\x1B[41m"
#define GREEN_BG "\x1B[42m"
#define YELLOW_BG "\x1B[43m"
#define BLUE_BG "\x1B[44m"
#define MAGENTA_BG "\x1B[45m"
#define CYAN_BG "\x1B[46m"
#define WHITE_BG "\x1B[47m"

// Combinações de texto e fundo
#define BLACK_WHITE_BG "\x1B[30;47m"
#define RED_WHITE_BG "\x1B[31;47m"
#define GREEN_WHITE_BG "\x1B[32;47m"
#define YELLOW_WHITE_BG "\x1B[33;47m"
#define BLUE_WHITE_BG "\x1B[34;47m"
#define MAGENTA_WHITE_BG "\x1B[35;47m"
#define CYAN_WHITE_BG "\x1B[36;47m"
#define WHITE_BLACK_BG "\x1B[37;40m"

// Estilos de Texto
#define BOLD "\x1B[1m"
#define FAINT "\x1B[2m"
#define ITALIC "\x1B[3m"
#define UNDERLINE "\x1B[4m"
#define BLINK "\x1B[5m"
#define INVERSE "\x1B[7m"
#define HIDDEN "\x1B[8m"
#define STRIKETHROUGH "\x1B[9m"

#endif // COLORS_H
