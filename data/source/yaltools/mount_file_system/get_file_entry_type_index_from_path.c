/* Retrieves the ${mount_tool_file_entry_type_description} index from a path
 * Returns 1 if successful, 0 if no such ${mount_tool_file_entry_type_description} index or -1 on error
 */
int mount_file_system_get_${mount_tool_file_entry_type}_index_from_path(
     mount_file_system_t *file_system,
     const system_character_t *path,
     size_t path_length,
     int *${mount_tool_file_entry_type}_index,
     libcerror_error_t **error )
{
	static char *function                    = "mount_file_system_get_${mount_tool_file_entry_type}_index_from_path";
	system_character_t character             = 0;
	size_t path_index                        = 0;
	int ${mount_tool_file_entry_type}_number = 0;
	int result                               = 0;

	if( file_system == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid file system.",
		 function );

		return( -1 );
	}
	if( file_system->path_prefix == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_MISSING,
		 "%s: invalid file system - missing path prefix.",
		 function );

		return( -1 );
	}
	if( path == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid path.",
		 function );

		return( -1 );
	}
	if( path_length > (size_t) ( SSIZE_MAX - 1 ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM,
		 "%s: invalid path length value exceeds maximum.",
		 function );

		return( -1 );
	}
	if( ${mount_tool_file_entry_type}_index == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid ${mount_tool_file_entry_type_description} index.",
		 function );

		return( -1 );
	}
	path_length = system_string_length(
	               path );

	if( ( path_length == 1 )
	 && ( path[ 0 ] == file_system->path_prefix[ 0 ] ) )
	{
		*${mount_tool_file_entry_type}_index = -1;

		return( 1 );
	}
	if( ( path_length < file_system->path_prefix_size )
	 || ( path_length > ( file_system->path_prefix_size + 3 ) ) )
	{
		return( 0 );
	}
#if defined( WINAPI )
	result = system_string_compare_no_case(
	          path,
	          file_system->path_prefix,
	          file_system->path_prefix_size - 1 );
#else
	result = system_string_compare(
	          path,
	          file_system->path_prefix,
	          file_system->path_prefix_size - 1 );
#endif
	if( result != 0 )
	{
		return( 0 );
	}
	${mount_tool_file_entry_type}_number = 0;

	path_index = file_system->path_prefix_size - 1;

	while( path_index < path_length )
	{
		character = path[ path_index++ ];

		if( ( character < (system_character_t) '0' )
		 || ( character > (system_character_t) '9' ) )
		{
			return( 0 );
		}
		${mount_tool_file_entry_type}_number *= 10;
		${mount_tool_file_entry_type}_number += character - (system_character_t) '0';
	}
	*${mount_tool_file_entry_type}_index = ${mount_tool_file_entry_type}_number - 1;

	return( 1 );
}

