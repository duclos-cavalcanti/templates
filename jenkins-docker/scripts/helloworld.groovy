def hello_world() {
    echo "hello world from groovy"
}

def build() {
    echo "building this application from groovy..."
}

def deploy() {
    echo "deploying version ${params.VERSION} from groovy..."
}

return this
