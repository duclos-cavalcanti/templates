###
# Installer stage
###
FROM jenkins/jenkins:lts
LABEL Author="Daniel Duclos-Cavalcanti"
LABEL Email="daniel.duclos-cavalcanti@gmail.com"
LABEL Maintainer="Daniel Duclos-Cavalcanti"

###
# Installing plugins example through jenkins-plugin-cli
###
# Installing prebuilt, custom plugins can be accomplished by copying the plugin HPI file into /usr/share/jenkins/ref/plugins/ within the Dockerfile:
# COPY --chown=jenkins:jenkins path/to/custom.hpi /usr/share/jenkins/ref/plugins/

# RUN jenkins-plugin-cli --plugins pipeline-model-definition github-branch-source:1.8

###
# Installing plugins example through plugins script
###
# COPY --chown=jenkins:jenkins plugins.txt /usr/share/jenkins/ref/plugins.txt
# RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt
