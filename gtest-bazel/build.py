def build_project():
    import os
    os.system("bazel build ...")

def main():
    import argparse
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)

    parser.parse_args()

    parser.add_argument('-e', '--example', required=False,
                        default="ex",
                        help='Example argument to script.')

    build_project()


if __name__ == '__main__':
    main()
