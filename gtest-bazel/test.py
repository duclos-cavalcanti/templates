test_project_name = "example_test"
op_system = ""

def symlink_test_report():
    import os
    from pathlib import Path
    
    p = Path("index.html")

    if (op_system.lower() == "linux" or op_system.lower() == "darwin"):
        p.symlink_to("test/reports/test/index.html")

def get_test_report():
    import os
    import platform

    op_system = platform.system()

    if (op_system.lower() == "linux" or op_system.lower() == "darwin"):
        os.system(f"python test/reports/html/gtest2html.py bazel-testlogs/test/{test_project_name}/test.xml test/reports/test/index.html > /dev/null")

    else:
        print("-- this is an unsupported operating system --")

def launch_test():
    import os
    os.system(f"bazel test --test_output=all //test:{test_project_name}")

def main():
    import argparse
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)

    parser.parse_args()

    parser.add_argument('-e', '--example', required=False,
                        default="ex",
                        help='Example argument to script.')

    launch_test()
    get_test_report()
    # symlink_test_report()


if __name__ == '__main__':
    main()
