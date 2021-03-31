struct triple_s *sss_create(void) {
  struct triple_s *sss = malloc(sizeof (struct triple_s));
  sss->len = 0;
  sss->maxlen = 1;
  sss->data = malloc(sss->maxlen * sizeof(char *));
  return sss;
}

void sss_destroy(struct triple_s *sss) {
  for (int i = 0; i < sss->len; i++) {
    free(sss->data[i]);
  }
  free(sss->data);
  free(sss);
}

void sss_add(struct triple_s *sss, const char *s) {
  assert(sss);
  int length = sss->len;

  int start_search = 0;
  int end_search = length - 1;
  int mid = (start_search + end_search) / 2;

  while (start_search <= end_search) {
    if (!strcmp(s, sss->data[mid])) {
      return; // str found, do not add to sss
    } else if (strcmp(s, sss->data[mid]) > 0) {
      start_search = mid + 1;
    } else if (strcmp(s, sss->data[mid]) < 0) {
      end_search = mid - 1;
    } 
    mid = (start_search + end_search) / 2;
  }
  // str not found add string to start index

  if (sss->len == sss->maxlen){
    sss->maxlen *= 2;
    sss->data = realloc(sss->data, sss->maxlen * sizeof(char *));
  }

  for (int i = length - 1; i >= start_search; i--) {
    sss->data[i + 1] = sss->data[i];
  }

  char *newstr = malloc((strlen(s) + 1) * sizeof(char));
  strcpy(newstr, s);

  sss->data[start_search] = newstr;
  sss->len += 1;

}


void sss_add_follows(struct triple_s *sss, const char *s) {
  assert(sss);

  if (sss->len == sss->maxlen){
    sss->maxlen *= 2;
    sss->data = realloc(sss->data, sss->maxlen * sizeof(char *));
  }
  char *newstr = malloc((strlen(s) + 1) * sizeof(char));
  strcpy(newstr, s);

  sss->data[sss->len] = newstr;
  sss->len += 1;
}




void sss_remove(struct triple_s *sss, const char *s) {
  assert(sss);
  int index = sss_search(sss, s);
  int last_ind = sss->len - 1;
  
  free(sss->data[index]);
  
  while (index + 1 <= last_ind) {
    sss->data[index] = sss->data[index + 1];
    index++;
  }
  
  sss->len -= 1;
  
}


int sss_count(const struct triple_s *sss) {
  assert(sss);
  return sss->len;
}

int sss_search(const struct triple_s *sss, const char *s) {
  assert(sss);
  int length = sss->len;

  int start_search = 0;
  int end_search = length - 1;
  int mid = (start_search + end_search) / 2;

  while (start_search <= end_search) {
    if (!strcmp(s, sss->data[mid])) {
      return mid;
    } else if (strcmp(s, sss->data[mid]) > 0) {
      start_search = mid + 1;
    } else if (strcmp(s, sss->data[mid]) < 0) {
      end_search = mid - 1;
    } 
    mid = (start_search + end_search) / 2;
  }

  return -1;
}

const char *sss_get(const struct triple_s *sss, int idx) {
  assert(sss);
  return sss->data[idx];

}
