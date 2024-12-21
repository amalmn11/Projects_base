#include "pch.h"


int main()
{
	Datelib d(3,2,2022);
	d.afficherdate();


	Datelib* D = new Datelib(3, 11, 2024);

	D->afficherdate();
}
