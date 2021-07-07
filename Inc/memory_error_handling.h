/*
 * memory_error_handling.h
 *
 *  Created on: Jun 30, 2021
 *      Author: florianfrank
 */

#ifndef INC_MEMORY_ERROR_HANDLING_H_
#define INC_MEMORY_ERROR_HANDLING_H_

enum MEM_ERROR
{
	MEM_NO_ERROR,
	MEM_REGISTER_NOT_SET,
	MEM_UNKNOWN_ERROR,
	MEM_TIMEOUT,
	MEM_HAL_INTERNAL_ERROR,
	MEM_HAL_BUSY,
	MEM_HAL_TIMEOUT,
	MEM_INTERFACE_NOT_SUPPORTED,
	MEM_INVALID_ARGUMENT,
	MEM_NOT_WRITTEN,
	MEM_UNEXPECTED_VALUE,
	MEM_INVALID_COMMAND

} typedef MEM_ERROR;



MEM_ERROR HAL_StatusTypeDefToErr(int status);

#endif /* INC_MEMORY_ERROR_HANDLING_H_ */