#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

string verifyKey(string k);


int main(int argc, string argv[])
{
    if(argc == 2)
    {
        int i = 0;
        int j = 0;

        //verifies key isalpha and converts to uppercase
        string k = verifyKey(argv[1]);
        int keyLen = strlen(k);

        //prompts user for string and stores it as variable
        printf("plaintext: ");
        string p = get_string();
        int msgLen = strlen(p);

        //builds new key that is the same length as the plaintext
        char newKey[msgLen];
        for(i = 0, j = 0; i < msgLen; i++, j++)
        {
            if(j == keyLen && isalpha(p[i]))
            {
                j = 0;
                newKey[i] = k[j];
            }
            else if(isalpha(p[i]))
            {
                newKey[i] = k[j];
            }
            else
            {
                j += -1;
            }
        }
        newKey[i] = '\0';


        //encrypts plaintext using the new key
        char encryption[msgLen];
        if(p != NULL)
            {
                //cycles through each letter of p and adds key value
                for(i = 0; i < msgLen; i++)
                {
                    if(isalpha(p[i]))
                    {
                        encryption[i] = ((p[i] + newKey[i]) % 26) + 'A';
                    }

                }
            }
        printf("key: %s\n", k);
        printf("plaintext: %s\n", p);
        printf("newkey: %s\n", newKey);
        printf("ciphertext: %s\n", encryption);
        return 0;
    }
    else
    {
        printf("Error: Command line arg count does not equal 2\n");
        return 1;
    }
}

string verifyKey(string key)
{
    int n = strlen(key);
    for(int i = 0; i < n; i++)
    {
        key[i] = toupper(key[i]);
        if isalpha(key[i])
        {
        }
        else
        {
            printf("Key invalid. Reenter key: \n");
            key = get_string();
            break;
        }
   }
  return key;
}