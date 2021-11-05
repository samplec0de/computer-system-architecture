import sys
from pathlib import Path

from lang_tool.common.exceptions import ParseError
from lang_tool.container import Container

if __name__ == '__main__':
    args = sys.argv
    if len(args) == 1 or args[1] not in ['-n', '-f']:
        print("Usage:\n"
              "    python3 -m lang_tool.cli -n <integer::count of elements> "
              "<str::output file> <str::output sorted file>\n"
              "or\n"
              "    python3 -m lang_tool.cli -f <str::input file> <str::output file> <str::output sorted file>\n")
    elif args[1] == '-n':
        if len(args) == 5:
            cnt = args[2]
            out_file = args[3]
            out_sorted_file = args[4]
            if not cnt.isdigit():
                print("Count of elements (-n value) must be integer")
            else:
                # рандомно
                container = Container(n_random=int(cnt))
        else:
            print("In random generator mode, use\n"
                  "    python3 -m lang_tool.cli -n <integer::count of elements> "
                  "<str::output file> <str::output sorted file>\n"
                  "Example:\n"
                  "    python3 -m lang_tool.cli -n 1000 outrnd_1.txt outrnd_2.txt")
    elif args[1] == '-f':
        if len(args) == 5:
            in_file = args[2]
            out_file = args[3]
            out_sorted_file = args[4]
            if Path(in_file).is_file():
                # из файла
                try:
                    container = Container(in_file)
                    with open(out_file, 'w') as out:
                        out.write(f"Filled container:\nContainer contains {len(container)} elements.\n")
                        for i, language in enumerate(container):
                            out.write(f"{i}: {language}\n")
                    container.sort()
                    with open(out_sorted_file, 'w') as out:
                        out.write(f"Sorted container:\nContainer contains {len(container)} elements.\n")
                        for i, language in enumerate(container):
                            out.write(f"{i}: {language}\n")
                except (ValueError, NotImplementedError, ParseError) as e:
                    print(f"{repr(e)}")
                except NotADirectoryError as e:
                    print(f"Error! {e.strerror}: {e.filename}")
            else:
                print("Input file does not exist")
        else:
            print("In file input mode, use\n"
                  "    python3 cli.py -f <str::input file> <str::output file> <str::output sorted file>\n"
                  "Example:\n"
                  "    python3 cli.py -f in.txt out_1.txt out_2.txt")
