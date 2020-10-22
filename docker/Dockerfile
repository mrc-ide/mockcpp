# Dockerfile for package buliding and running this package
FROM rocker/r-ver:4.0.2

RUN R -e "install.packages('remotes')"

COPY DESCRIPTION /home/docker/mockcpp/

RUN R -e "remotes::install_deps('/home/docker/mockcpp', dependencies = TRUE)"
