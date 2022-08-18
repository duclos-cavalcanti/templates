package main

import (
	"fmt"

    "rsc.io/quote"

	"github.com/duclos-cavalcanti/go-project-template/cmd/greetings"
	"github.com/duclos-cavalcanti/go-project-template/cmd/hello"
)

func main() {
	message := greetings.Welcome("Gladys")

	hello.HelloWorld()
	hello.HelloWorld()
	hello.HelloWorld()
	hello.HelloWorld()
	hello.HelloWorld()

	fmt.Println(message)
    fmt.Println(quote.Go())
}
