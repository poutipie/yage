import os
import ycm_core


project_dir = os.path.dirname(os.path.abspath(__file__))
compilation_database_folder = os.path.join(project_dir, "build/")

database = ycm_core.CompilationDatabase( compilation_database_folder )

additional_flags = [
    '-isystem', '/usr/local/include',
    '-isystem', '/usr/include',
]


def IsHeaderFile( filename ):
  extension = os.path.splitext( filename )[ 1 ]
  return extension in [ '.h', '.hxx', '.hpp', '.hh' ]


def FindCorrespondingSourceFile( filename ):
  if IsHeaderFile( filename ):
    basename = os.path.splitext( filename )[ 0 ]
    for extension in SOURCE_EXTENSIONS:
      replacement_file = basename + extension
      if os.path.exists( replacement_file ):
        return replacement_file
  return filename

def Settings( **kwargs):

    if kwargs[ 'language' ] == 'cfamily':
        # If the file is a header, try to find the corresponding source file and
        # retrieve its flags from the compilation database if using one. This is
        # necessary since compilation databases don't have entries for header files.
        # In addition, use this source file as the translation unit. This makes it
        # possible to jump from a declaration in the header file to its definition
        # in the corresponding source file.
        filename = FindCorrespondingSourceFile( kwargs[ 'filename' ] )
        compilation_info = database.GetCompilationInfoForFile( filename )

        # Bear in mind that compilation_info.compiler_flags_ does NOT return a
        # python list, but a "list-like" StringVec object.
        final_flags = list(compilation_info.compiler_flags_) + additional_flags
        
        return {
            'flags': final_flags,
            'include_paths_relative_to_dir': compilation_info.compiler_working_dir_,
            'override_filename': filename
        }

    return {}

