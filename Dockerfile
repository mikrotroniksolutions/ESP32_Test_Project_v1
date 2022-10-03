FROM python:3.9.0-slim

ENV APP_VERSION="6.1.4" \
    APP="platformio-core"

LABEL app.name="${APP}" \
      app.version="${APP_VERSION}" \
      maintainer="Mikrotronik Solutions <mikrotroniksolutions@gmail.com >"

RUN pip install -U platformio==${APP_VERSION} && \
    mkdir -p /workspace && \
    mkdir -p /.platformio && \
    chmod a+rwx /.platformio && \
    apt update && apt install -y git && apt-get clean autoclean && apt-get autoremove --yes && rm -rf /var/lib/{apt,dpkg,cache,log}/

RUN pio pkg install -g -p espressif32 && \
    pio pkg install -g -t tool-clangtidy && \
    pio pkg install -g -t tool-cppcheck && \
    pio pkg install -g -t tool-mkfatfs && \
    pio pkg install -g -t tool-mklittlefs && \
    pio pkg install -g -t tool-mkspiffs && \
    pio pkg install -g -t tool-scons && \
    pio pkg install -g -t contrib-piohome

USER 1001

WORKDIR /workspace

ENTRYPOINT ["platformio"] 