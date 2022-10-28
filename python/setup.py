from setuptools import setup, find_packages

with open("README.md", "r") as f:
    page_description = f.read()

with open("requirements.txt") as f:
    requirements = f.read().splitlines()

setup(
    name="project",
    version="0.0.1",
    author="Daniel Duclos-Cavalcanti",
    author_email="daniel.duclos.cavalcanti@gmail.com",
    description="project thing-a-magigy",
    long_description=page_description,
    long_description_content_type="text/markdown",
    url="https://github.com/duclos-cavalcanti/project",
    packages=find_packages(),
    entry_points={"console_scripts": ["call=project.__main__:main"]},
    install_requires=requirements,
    python_requires='>=3.8',
)
