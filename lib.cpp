/**
	\file
	Библиотека функций печати версии приложения.
*/	

/**
	\defgroup lib_c Модуль печати версии приложения
	@{
*/

#include <iostream>
#include "lib.h"

/**
	\warning deprecated
	Номер сборки
*/
int version()
{
	return PROJECT_VERSION_PATCH;
}


/**
	Основной номер
*/
int version_major()
{
	return PROJECT_VERSION_MAJOR;
}


/**
	Дополнительный номер
*/
int version_minor()
{
	return PROJECT_VERSION_MINOR;
}


/**
	Номер сборки
*/
int version_patch()
{
	return PROJECT_VERSION_PATCH;
}

/**
	@}
*/
