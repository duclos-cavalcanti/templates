# Java Gradle Template
The best resource will of course be found in the gradle's official [website](https://docs.gradle.org/current/samples/sample_building_java_applications.html). Here the options chosen through `gradle init` were:

1. application
2. Java
3. Groovy
4. JUnit 4
5. java-gradle-template

## Project
```sh
├── gradle            # generated folder for wrapper files
│   └── wrapper
│       ├── gradle-wrapper.jar
│       └── gradle-wrapper.properties
├── gradlew           # gradle wrapper start scripts
├── gradlew.bat       # gradle wrapper start scripts
├── settings.gradle   # Settings file to define build name and subprojects
└── app
    ├── build.gradle  # build script of app project
    └── src           # default java source folder
        ├── main
        │   └── java
        │       └── demo
        │           └── App.java
        └── test      # default java test source folder
            └── java
                └── demo
                    └── AppTest.java

```

## Targets

1. make build
2. make scan
3. make run
4. make clean
