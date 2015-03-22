#ifndef _SYMBOLE_
#define _SYMBOLE_

#include <stdio.h>
#include <iostream>

enum Symbole {compas, tablette, roue};

std::ostream& operator << (std::ostream& Out, Symbole symbole);

#endif
