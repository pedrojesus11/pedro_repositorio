#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUNDS 12
#define MAX_SCORE 10
#define MIN_SCORE 9
#define KNOCKDOWN_POINTS 2
#define INITIAL_PRIZE 100000

int main() {
    int i, j, score, knockdown, winner_score = 0, loser_score = 0, winner_rounds = 0, loser_rounds = 0;
    float winner_prize, loser_prize;
    char decision[3];

    // Simulación de los resultados de los 12 rounds
    for (i = 1; i <= MAX_ROUNDS; i++) {
        printf("Round %d\n", i);

        // Simulación de los puntajes y los knockdowns en cada round
        for (j = 1; j <= 2; j++) {
            printf("Peleador %d: ", j);
            scanf("%d", &score);
            printf("Knockdown? (0 = no, 1 = si): ");
            scanf("%d", &knockdown);

            if (score == MAX_SCORE && knockdown == 1) {
                score -= KNOCKDOWN_POINTS;
            }
            else if (score == MIN_SCORE && knockdown == 0) {
                score += KNOCKDOWN_POINTS;
            }

            if (j == 1) {
                winner_score += score;
                loser_score += MAX_SCORE - score;
                if (score > MAX_SCORE - score) {
                    winner_rounds++;
                }
                else if (score < MAX_SCORE - score) {
                    loser_rounds++;
                }
            }
            else {
                winner_score += MAX_SCORE - score;
                loser_score += score;
                if (score < MAX_SCORE - score) {
                    winner_rounds++;
                }
                else if (score > MAX_SCORE - score) {
                    loser_rounds++;
                }
            }
        }
    }

    // Determinación del tipo de decisión
    if (winner_score > loser_score) {
        if (winner_rounds == MAX_ROUNDS) {
            sprintf(decision, "UD");
        }
        else if (winner_rounds >= 7) {
            sprintf(decision, "MD");
        }
        else {
            sprintf(decision, "SD");
        }
    }
    else {
        if (loser_rounds == MAX_ROUNDS) {
            sprintf(decision, "UD");
        }
        else if (loser_rounds >= 7) {
            sprintf(decision, "MD");
        }
        else {
            sprintf(decision, "SD");
        }
    }

    // Cálculo de los premios de los boxeadores
    winner_prize = INITIAL_PRIZE + (INITIAL_PRIZE * (winner_rounds * 0.05));
    loser_prize = 0.6 * INITIAL_PRIZE;

    printf("Puntuacion Final:\n");
    printf("Ganador: %d puntos\n", winner_score);
    printf("Perdedor: %d puntos\n", loser_score);
    printf("\nRounds Ganados:\n");
    printf("Ganador: %d rounds\n", winner_rounds);
    printf("Perdedor: %d rounds\n", loser_rounds);
    printf("\nTipo de Victoria: %s\n", decision);
    printf("\nPremios:\n");
    printf("Ganador: $%.2f\n", winner_prize);
    printf("Perdedor: $%.2f\n", loser_prize);

    return 0;
}
