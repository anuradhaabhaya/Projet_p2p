#include <openssl/evp.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void print_as_hex (const unsigned char *digest, int len) {
  int i;
  for(i = 0; i < len; i++){
    printf ("%02x", digest[i]);
  }
  printf("\n");
}


static void calculate_md5_of(const void *content, ssize_t len){
  EVP_MD_CTX mdctx;
  unsigned char md_value[EVP_MAX_MD_SIZE];
  unsigned int md_len;
  
  EVP_DigestInit(&mdctx, EVP_md5());
  EVP_DigestUpdate(&mdctx, content, (size_t) len);
  EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
  EVP_MD_CTX_cleanup(&mdctx);
  printf("md5(%s) = ", (char*) content);
  print_as_hex(md_value, md_len); 
}

int main()
{

  /* http://en.literateprograms.org/MD5_sum_(C,_OpenSSL)#chunk use:md5sum.c : 
  TODO: struct taille d'un fichier : stat */

  char string[] = "antoine";

  calculate_md5_of(string, strlen(string));

  return 0;
}