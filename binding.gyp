{
  "targets": [
    {
      "target_name": "lfsr64",
      "sources": [ "src/lfsr64.cc" ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
