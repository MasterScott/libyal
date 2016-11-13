/* Retrieves the ${value_description}
 * Returns a Python object if successful or NULL on error
 */
PyObject *${python_module_name}_file_get_${value_name}(
           ${python_module_name}_file_t *${python_module_name}_file,
           PyObject *arguments ${python_module_name_upper_case}_ATTRIBUTE_UNUSED )
{
	PyObject *integer_object = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "${python_module_name}_file_get_${value_name}";
	uint32_t value_32bit     = 0;
	int result               = 0;

	${python_module_name_upper_case}_UNREFERENCED_PARAMETER( arguments )

	if( ${python_module_name}_file == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid file.",
		 function );

		return( NULL );
	}
	Py_BEGIN_ALLOW_THREADS

	result = ${library_name}_file_get_${value_name}(
	          ${python_module_name}_file->file,
	          &value_32bit,
	          &error );

	Py_END_ALLOW_THREADS

	if( result == -1 )
	{
		${python_module_name}_error_raise(
		 error,
		 PyExc_IOError,
		 "%s: unable to retrieve ${value_description}.",
		 function );

		libcerror_error_free(
		 &error );

		return( NULL );
	}
	else if( result == 0 )
	{
		Py_IncRef(
		 Py_None );

		return( Py_None );
	}
	integer_object = ${python_module_name}_integer_unsigned_new_from_64bit(
	                  (uint64_t) value_32bit );

	return( integer_object );
}

