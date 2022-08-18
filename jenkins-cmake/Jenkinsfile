// Necessary plugins:
//      Credentials
//      Credentials Binding

// Jenkins Environment variables can be found in http://localhost:8080/env-vars.html/
pipeline {
    agent any
        // {
        // docker { 
        //     image 'vivado:2018.3'            
        // }

    parameters {
        booleanParam(name: 'executeTests', defaultValue: true, description: '')
    }

    // tools {
    //     maven 'Maven'
    // }

    environment {
        VERSION = '0.0.1'
    }

    stages {
        stage('Checkout') {
            steps { 
                // checkout scm
                echo "Checkout branch..."
            }
        }
        stage('Build') {
            steps {
                echo "Building version ${VERSION}..."
                sh 'make build'
            }
        }

        stage('Test') {
            when { // example of conditional
                expression {
                    env.BRANCH_NAME == 'master'
                }
            }
            steps {
                echo "Testing..."
                sh 'make dummy1'
                sh 'make dummy2'
            }
        }

        stage('Run') {
            steps {
                echo "Running..."
                sh 'make run'
            }
        }
    }

    post {
        always {  // always
            echo "Cleaning up..."
            sh 'make clean'
        }
        success {
            echo "Succeeded..."
        }
        failure {
            echo "Failed..."
        }
    }
}
