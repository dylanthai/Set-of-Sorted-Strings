// Note: This was part of an assignment so I did not create the .h file. The University of Waterloo Computer Science Instructors did. I wrote the code in the .c module

struct triple_s;

// The following applies to all functions
// requires: all sss parameters are valid (not NULL) 
//           all s parameters are valid (not NULL)
// time: (n) is the number of strings in the sss
//       (m) is the length of the string s

// sss_create() creates a new SSS ADT
// effects: allocates memory (you must call sss_destroy)
// time: O(1)
struct triple_s *sss_create(void);

// sss_destroy(sss) destroys sss
// requires: sss is valid (not NULL)
// effects: sss is no longer valid
// time: O(n)
void sss_destroy(struct triple_s *sss);

// sss_add(sss, s) adds s to sss in the correct index (lexicographically)
// notes: if s already exists, there is no effect
//        when s is added, the indices of words that lexicographically
//          follow s will be changed (+1) because s is added into the "middle"
// effects: may modify sss
// time: O(n + m*logn)
void sss_add(struct triple_s *sss, const char *s);

// sss_add_follows(sss, s) adds s to the "end" of the sss
// requires: s lexicographically follows all strings already in sss
// effects: modifies sss
// time: O(m) [amortized]
void sss_add_follows(struct triple_s *sss, const char *s);

// sss_remove(sss, s) removes s from sss (if it exists)
// notes: if s is removed, the indices of words that lexicographically
//          follow s will be changed (-1)
// effects: may modify sss
// time: O(n + m*logn)
void sss_remove(struct triple_s *sss, const char *s);

// sss_count(sss) gets the number of strings in sss
// time: O(1)
int sss_count(const struct triple_s *sss);

// sss_search(sss, s) finds the index of s in sss
// note: returns -1 if s does not appear in the sss
// time: O(m*logn)
int sss_search(const struct triple_s *sss, const char *s);

// sss_get(sss, idx) retrieves a pointer to the string in sss
//   at the given idx (index)
// requires: 0 <= idx < sss_count(sss)
// time: O(1)
const char *sss_get(const struct triple_s *sss, int idx);
