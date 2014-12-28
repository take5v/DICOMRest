DICOMRest
=========

Сервис хранения и доступа DICOM изображений

DICOMRest API

  Отправка одного DICOM файла на сервис осуществляется POST запросом
  
    curl -X POST http://localhost/instances --data-binary img0001.dcm
    В ответ вернётся следующий JSON файл:
    { 
      "ID" : "e87da270-c52b-4f2a-b8c6-bae25928d0b0",
      "Path" : "/instances/e87da270-c52b-4f2a-b8c6-bae25928d0b0",
      "Status" : "Success"
    }
    
  ID - публичный идентификатор изображения, которое хранится на диске, Path - путь к файлу на диске, Status - результат выполнения операции.
  
  GET запрос всех объектов типа изображений:
  
    curl http://localhost/instances
    [
      "f408c502-b37f-4697-b269-437784c7c865",
      "e87da270-c52b-4f2a-b8c6-bae25928d0b0"
    ]
  
  GET запрос одного изображения:
  
    curl http://localhost/instances/e87da270-c52b-4f2a-b8c6-bae25928d0b0/
    {
      "ID" : "e87da270-c52b-4f2a-b8c6-bae25928d0b0",
      "PatientName" : "Alex"
    }
  
  POST запрос на модификацию метаданных изображения:
  
    curl -X POST http://localhost/instances/e87da270-c52b-4f2a-b8c6-bae25928d0b0/modify -d '{"Replace":"PatientName":"SuperAlex"}'
    {
      "ID" : "e87da270-c52b-4f2a-b8c6-bae25928d0b0",
      "PatientName" : "SuperAlex"
    }
  
  
