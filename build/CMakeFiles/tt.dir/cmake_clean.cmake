file(REMOVE_RECURSE
  "tt.pdb"
  "tt"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/tt.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
