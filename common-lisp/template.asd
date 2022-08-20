(asdf:defsystem #:template
  :description "Describe <project name> here"
  :author "Your Name <your.name@example.com>"
  :license "Specify license here"
  :serial t
  ;; Refs: https://goo.gl/CY5cLK, https://stackoverflow.com/a/21663603/747872
  :depends-on (:local-time)
  :components ((:module "src"
                :serial t
                :components ((:file "main"))))
  :in-order-to ((asdf:test-op (asdf:test-op #:template/test))))


(asdf:defsystem #:template/test
  :serial t
  :depends-on (:template
               (:version "prove" "1.0.0"))
  :defsystem-depends-on (:prove-asdf)
  :components ((:module "test"
                :components ((:test-file "main"))))
  :perform (asdf:test-op :after (op c)
                         (funcall (intern #.(string :run) :prove) c)))
