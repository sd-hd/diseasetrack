FROM debian:buster-slim
RUN apt update
RUN apt install apt-transport-https ca-certificates gnupg pkg-config zip g++ zlib1g-dev unzip python3 curl libboost-dev libboost-program-options-dev libboost-iostreams-dev libboost-system-dev libboost-filesystem-dev git libssl-dev libsodium-dev libcrypto++-dev -y && echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list && curl https://bazel.build/bazel-release.pub.gpg | apt-key add - && apt update && apt install bazel -y
RUN git clone -b nginx https://github.com/sd-hd/diseasetrack.git && cd diseasetrack && bazel build //...
VOLUME ["/diseasetrack"]
COPY start.sh /start.sh
COPY cert.conf cert.conf
RUN openssl req -x509 -new -nodes -config cert.conf -days 365 -keyout /tmp/privkey.key -out /tmp/fullchain.crt
CMD ["./start.sh"]
EXPOSE 12345
