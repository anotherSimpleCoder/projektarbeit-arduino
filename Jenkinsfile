pipeline {
    agent {
        docker {
            image 'rocker/r-rmd'
            args '-u root' 
        }
    }

    stages {
        stage('Build PDF') {
            steps {
                sh 'bash render.sh'
                archiveArtifacts artifacts: '*.pdf', fingerprint: true
            }
        }
    }
}