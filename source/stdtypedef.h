/*
 * stdtypedef.h
 *
 *  Para redefinir tipos de datos
 */

#ifndef STDTYPEDEF_H_
#define STDTYPEDEF_H_

typedef unsigned char 	T_UBYTE;
typedef unsigned short	T_UWORD;

#define TRUE	((T_UBYTE)(1U)) //El () exterior por si se hacen operaciones con ellos
#define FALSE	((T_UBYTE)(0U))

#endif /* STDTYPEDEF_H_ */
