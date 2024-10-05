#include <curl/easy.h>
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <libxml2/libxml/HTMLparser.h>
#include <libxml2/libxml/xpath.h>

struct Memory {
  char *response;
  size_t size;
}

static size_t WriteCallback(void *data, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct Memory *mem = (struct Memory *)userp;

  char *ptr = realloc(mem->response, mem->size + realsize + 1);
  if(ptr == NULL) {
    printf("TIdak dapat Mengalokasikan memoru.\n");
    return 0;
  }

  mem->response = ptr;
  memcpy(&(mem->response[mem->size]), data, realsize);
  mem->size += realsize;
  mem->response[mem->size] = 0;

  return realsize;
}

char *get_page_content(const char *url) {
  CURL *curl;
  CURLcode res;
  struct Memory chunk = {0};

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() gagal: %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
  }
  return chunk.response;
}


void parse_html(const char *html) {
  htmlDocPtr doc = htmlReadMemory(html, strlen(html), NULL, NULL, HTML_PARSE_NOWARNING);
  if (doc == NULL){
    printf("gagal memuat html\n");
    return;
  }

  xmlXPathContextPtr context = xmlXPathNewContext(doc);
  xmlXPathObjectPtr result = xmlXPathEvalExpression((xmlChar*)"//a/@href", context);

  if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
    printf("tidak ditemukan link\n");
    return;
  } else {
    for (int i = 0; i < result->nodesetval->nodeNr; i++) {
      xmlNodePtr node = result->nodesetval->nodeTab[i]->children;
      if (node && node-content) {
          printf("Link: %s\n", node-content);
      }
    }
  }

  xmlXPathFreeObject(result);
  xmlXPathFreeContext(context);
  xmlFreDoc(doc);
}

int main() {
  const char *url = "http://localhost.local";
  char *html = get_page_content(url);
  
  if (html){
    parse_html(html);
    free(html);
  } else {
    printf("GAGAL MENGAMBIL CONTENT %s\n", url);
  }

  return 0;
}
