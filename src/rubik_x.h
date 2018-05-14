#ifndef __RUBIK_DISPLAY_H__
# define __RUBIK_DISPLAY_H__

void rubik_x_init(void);
void rubik_x_clean(void);
void rubik_x_dump(struct rubik *rubik, uint32_t x_orig, uint32_t y_orig);
void rubik_x_pause(void);

#endif /* !__RUBIK_DISPLAY_H__ */
