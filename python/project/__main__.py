import argparse

from . import core

def get_args() -> argparse.Namespace:
    """Get the script arguments."""
    description = "launcher - manages and creates multiplexer sessions"
    parser = argparse.ArgumentParser(description=description)

    parser.add_argument(
        "-u",
        "--username",
        required=True,
        help="username",
    )

    parser.add_argument(
        "-p",
        "--password",
        required=True,
        help="user's password",
    )

    args = parser.parse_args()
    return args

def main():
    """Main script function."""
    core.start()

if __name__ == "__main__":
    main()
