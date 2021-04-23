struct StringBuilder;

extern struct StringBuilder* make_sb(void);
extern void sb_append(struct StringBuilder* this, const char* s);
extern void sb_append_long(struct StringBuilder* this, long l);
extern void sb_append_double(struct StringBuilder* this, double d);
extern const char* sb_string(struct StringBuilder* this);
