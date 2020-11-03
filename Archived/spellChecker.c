#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char* word = nextWord(file);
    assert(word != NULL);
    while(word != NULL){
      hashMapPut(map, word, 1);
      free(word);
      word = nextWord(file);
    }
}

/**
  *  Calculates the Levenshtein distance
  *  @param char
  *  @param char
  */

#define minimum(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

int LevenshteinDistance(char* s1, char* s2){
    int substitutionCost = 0;
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int matrix[length1+1][length2+1];
    for(int i = 0; i <= length1; i++){
      for(int j = 0; j <= length2; j++){
        matrix[i][j] = 0;
      }
    }
    for(int i = 1; i <= length1; i++){
      matrix[i][0] = i;
    }
    for(int j = 1; j <= length2; j++){
      matrix[0][j] = j;
    }
    
    
    for(int j = 1; j <= length2; j++){
      for(int i = 1; i <= length1; i++){
        if(s1[i] == s2[j])
          substitutionCost = 0;
        else
          substitutionCost = 1;
        matrix[i][j] = minimum(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + substitutionCost);
   }
   }
  return (matrix[length1][length2]);
}


/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
 

int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        
        
        
        // Implement the spell checker code here..
         for(int i = 0; i <= strlen(inputBuffer); i++){
           if(inputBuffer[i] >= 'A' && inputBuffer[i] <= 'Z')
              inputBuffer[i] = inputBuffer[i] + 32;
         }
        if(hashMapContainsKey(map, inputBuffer) == 1){
                printf("The inputted word ... is spelled correctly \n");
        }
            
        else{
          printf("The inputted word ... is spelled incorrectly \n");
          char* candidates[5];
          for(int i = 0; i < 5; i++){
            candidates[i] = malloc(sizeof(char) * 256);
            assert(candidates[i] != NULL);
          }
          int dist [5] = {0,0,0,0,0};
          for(int i = 0; i < hashMapCapacity(map); i++){
            HashLink* link = map->table[i];
            while(link != NULL){
              int levenDist = LevenshteinDistance(inputBuffer, link->key);
              for(int j = 0; j < 5; j++){
                if((dist[j] == 0) || (dist[j] > levenDist)){
                  dist[j] = levenDist;
                  strcpy(candidates[j], link->key);
                  break;
                }
              }
              link = link->next;
            }
            
          }
         for(int i = 0; i < 5; i++){
            printf("Did you mean ... %s? \n", candidates[i]);
         }
          for(int i = 0; i < 5; i++){
            free(candidates[i]);
          }
      }        
      
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
     }   
    
    
    hashMapDelete(map);
    return 0;
}

