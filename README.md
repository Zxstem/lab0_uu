# IEE240 - Laboratorio 0 - 2021-2

## Instrucciones:
- Para clonar el repositorio y trabajar de forma local, realizar lo siguiente en el **terminal de Ubuntu**. Dentro de `<carpeta-del-repositorio>` encontrará todos los archivos necesarios para el desarrollo del laboratorio.
```shell
git clone <link-repositorio-alumno>
```
```shell
cd <carpeta-del-repositorio>
```

> **NOTA: En caso tenga algún error clonando el repositorio, revisar el siguiente [enlace](https://github.blog/2020-12-15-token-authentication-requirements-for-git-operations/). Se recomienda el uso de una llave SSH.**

- Cada carpeta contiene un archivo `README.md` con el enunciado de la pregunta. Puede visualizarlo directamente en su repositorio en el explorador web.

- Recordar que para poder ejecutar los archivos con extensión `.sh` debe realizar lo siguiente:
```shell
chmod 777 nombre_de_archivo.sh
```

- **La prueba inicia a las 8:00 pm y termina a las 10:00 pm. El sistema (GitHub Classroom) cierra a las 10:00pm, no se calificarán entregas (`push`) luego de esa hora.**

- **En caso se detecte plagio en alguno de sus códigos, se iniciará el proceso correspondiente definido por la Facultad de Ciencias e Ingeniería.**

## Subir solución a GitHub para revisión.
Al terminar el laboratorio y luego de validar localmente la correcta ejecución de su programa, realizar un `push` de su solución a su laboratorio para su corrección. Para ello ejecute los siguientes comandos en un **terminal de Ubuntu**. 

> **NOTA: Los comandos a continuación debe ejecutarlos dentro de la carpeta `<carpeta-del-repositorio>`.**

- Verificar con el siguiente comando que se han modificado los archivos correctos. Debería aparecer en rojo los archivos modificados durante el laboratorio.
```
git status
```
- Para añadir los archivos a git:
```
git add .
```
- Para subir sus códigos al repositorio remoto (GitHub):
```
git commit -m "<ponga-aqui-un-comentario-util>"
```
```shell
git push
```
- Cualquier consulta comuníquese con su JP.