#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9
// Print tables (ranks, prefs, pairs, locked)
#define VERBOSE 0
// 1 if we get data from a file, 0 for manual input
#define USE_FILE 0
// if we use a file, we need to specify the lengh of one line
#define FILE_MAX_LINE_SIZE 8

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct {
  int winner;
  int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool isLocked(int start, int end);
// Functions for VERBOSE
void print_ranks(int vote_number, int voter_count, int ranks[]);
void print_preferences(void);
void print_pairs(void);
void print_locked(void);

int main(int argc, string argv[]) {
  // Check for invalid usage
  if (argc < 2) {
    printf("Usage: tideman [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX) {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++) {
    candidates[i] = argv[i + 1];
  }

  // Clear graph of locked in pairs
  for (int i = 0; i < candidate_count; i++) {
    for (int j = 0; j < candidate_count; j++) {
      locked[i][j] = false;
    }
  }

  pair_count = 0;
  int voter_count = get_int("Number of voters: ");

  // read data from a file if we use it
  FILE *votes = NULL;
  if (USE_FILE) {
    votes = fopen("tideman_votes.txt", "r");
    if (votes == NULL) {
      printf("Error opening file.\n");
      return 1;
    }
  }

  // Query for votes
  for (int i = 0; i < voter_count; i++) {
    // ranks[i] is voter's ith preference
    int ranks[candidate_count];

    // Query for each rank
    for (int j = 0; j < candidate_count; j++) {
      if (USE_FILE) {
        char buffer[FILE_MAX_LINE_SIZE];
        fscanf(votes, "%s", buffer);
        if (!vote(j, buffer, ranks)) {
          printf("Invalid vote.\n");
          return 3;
        }
      } else {
        string name = get_string("Rank %i: ", j + 1);
        if (!vote(j, name, ranks)) {
          printf("Invalid vote.\n");
          return 3;
        }
      }
    }

    // If VERBOSE is 1
    print_ranks(i, voter_count, ranks);

    record_preferences(ranks);
  }

  // If VERBOSE is 1
  print_preferences();
  add_pairs();
  sort_pairs();
  lock_pairs();
  print_winner();

  return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[]) {
  // TODO
  for (int i = 0; i < candidate_count; i++) {
    if (strcmp(candidates[i], name) == 0) {
      ranks[rank] = i;
      return true;
    }
  }

  return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[]) {
  // TODO
  for (int i = 0; i < candidate_count; i++) {
    for (int j = i + 1; j < candidate_count; j++) {
      preferences[ranks[i]][ranks[j]]++;
    }
  }
  return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void) {
  // TODO
  pair_count = 0;
  for (int i = 0; i < candidate_count; i++) {
    for (int j = i + 1; j < candidate_count; j++) {
      if (preferences[i][j] > preferences[j][i]) {
        pairs[pair_count].winner = i;
        pairs[pair_count].loser = j;
        pair_count++;
      } else if (preferences[j][i] > preferences[i][j]) {
        pairs[pair_count].winner = j;
        pairs[pair_count].loser = i;
        pair_count++;
      }
    }
  }

  print_pairs();

  return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void) {
  // TODO
  // Selection sort
  // for (int i = 0; i < pair_count - 1; i++)
  // {
  //     int max = preferences[pairs[i].winner][pairs[i].loser];
  //     int idx = i;

  //     for (int j = i + 1; j < pair_count; j++)
  //     {
  //         if (max <= preferences[pairs[j].winner][pairs[j].loser])
  //         {
  //             max = preferences[pairs[j].winner][pairs[j].loser];
  //             idx = j;
  //         }
  //     }

  //     if (i != idx)
  //     {
  //         pair tmp = pairs[i];
  //         pairs[i] = pairs[idx];
  //         pairs[idx] = tmp;
  //     }
  // }

  // Bubble sort
  while (true) {
    bool swapped = false;
    for (int i = 0; i < pair_count - 2; i++) {
      if (preferences[pairs[i].winner][pairs[i].loser] <
          preferences[pairs[i + 1].winner][pairs[i + 1].loser]) {
        pair tmp = pairs[i];
        pairs[i] = pairs[i + 1];
        pairs[i + 1] = tmp;
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }

  print_pairs();

  return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void) {
  // TODO
  for (int i = 0; i < pair_count; i++) {
    if (!isLocked(pairs[i].loser, pairs[i].winner)) {
      locked[pairs[i].winner][pairs[i].loser] = true;
    }
    if (VERBOSE) {
      // prints the link with '+' if it's not a loop, '-' if it would create a
      // loop
      printf("%s Ref: %s -> %s\n",
             (locked[pairs[i].winner][pairs[i].loser]) ? "+" : "-",
             candidates[pairs[i].winner], candidates[pairs[i].loser]);
    }
  }

  print_locked();
}

// Print the winner of the election
void print_winner(void) {
  // if the candidate don't have arrows pointing at them
  // then it's the source
  for (int i = 0; i < candidate_count; i++) {
    bool isSource = true;
    for (int j = 0; j < candidate_count; j++) {
      if (locked[j][i]) {
        isSource = false;
        break;
      }
    }

    if (isSource) {
      printf("%s\n", candidates[i]);
      return;
    }
  }
  return;
}

// determines if the path exists according to 'locked' array
bool isLocked(int start, int end) {
  if (start == end) {
    return true;
  }

  for (int i = 0; i < candidate_count; i++) {
    if (locked[start][i] && isLocked(i, end)) {
      return true;
    }
  }

  return false;
}

// Prints all ranks as a table, if VERBOSE is 1
void print_ranks(int vote_number, int voter_count, int ranks[]) {
  if (!VERBOSE) {
    return;
  }

  if (vote_number == 0) {
    printf("Ranks:\n");
    for (int i = 0; i < candidate_count; i++) {
      printf(" __ ");
    }
    printf("\n");
  }

  printf("|");
  for (int i = 0; i < candidate_count; i++) {
    printf(" %i |", (int)ranks[i]);
  }

  if (vote_number == voter_count - 1) {
    printf("\n");
    for (int i = 0; i < candidate_count; i++) {
      printf(" ‾‾ ");
    }
  }

  printf("\n");

  return;
}

// Prints all preferences as a table, if VERBOSE is 1
void print_preferences(void) {
  if (!VERBOSE) {
    return;
  }

  printf("Preferences:\n");

  for (int i = 0; i < candidate_count; i++) {
    printf(" __ ");
  }

  printf("\n");

  for (int i = 0; i < candidate_count; i++) {
    printf("|");
    for (int j = 0; j < candidate_count; j++) {
      printf(" %i |", (int)preferences[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < candidate_count; i++) {
    printf(" ‾‾ ");
  }

  printf("\n");

  return;
}

// Prints all pairs, if VERBOSE is 1
void print_pairs(void) {
  if (!VERBOSE) {
    return;
  }

  for (int i = 0; i < pair_count; i++) {
    printf("%s(%i, %i)", (i == 0) ? "" : ", ", pairs[i].winner, pairs[i].loser);
  }
  printf("\n\n");
}

// Prints 'locked' array as a table, if VERBOSE is 1
void print_locked(void) {
  if (!VERBOSE) {
    return;
  }

  printf("\nLocked:\n");
  for (int i = 0; i < candidate_count; i++) {
    printf(" __ ");
  }
  printf("\n");
  for (int i = 0; i < candidate_count; i++) {
    printf("|");
    for (int j = 0; j < candidate_count; j++) {
      printf(" %i |", (int)locked[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < candidate_count; i++) {
    printf(" ‾‾ ");
  }

  printf("\n");
  printf("\n");

  return;
}
